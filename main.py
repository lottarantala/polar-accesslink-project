import json
import requests
import webbrowser
from urllib.parse import urlparse, parse_qs
from requests.auth import HTTPBasicAuth

def read_accesslink_info(filepath:str) -> dict:
    with open(filepath, 'r') as f:
        info = json.load(f)
    return info

def get_authorization_code_url(client_id: str, redirect_uri: str) -> str:
    return (
        "https://flow.polar.com/oauth2/authorization"
        f"?response_type=code&client_id={client_id}&redirect_uri={redirect_uri}"
    )

def exchange_code_for_token(code: str, client_id: str, client_secret: str, redirect_uri: str) -> dict:
    token_url = "https://polarremote.com/v2/oauth2/token"
    data = {
        "grant_type": "authorization_code",
        "code": code,
        "redirect_uri": redirect_uri
    }
    auth = HTTPBasicAuth(client_id, client_secret)
    response = requests.post(token_url, data=data, auth=auth)
    response.raise_for_status()
    return response.json()

if __name__=="__main__":
    config = read_accesslink_info("accesslink_information.json")
    client_id = config["client_id"]
    client_secret = config["client_secret"]
    redirect_uri = config["redirect_uri"]

    # Step 1: Open browser to request user authorization
    auth_url = get_authorization_code_url(client_id, redirect_uri)
    print("Open this URL in your browser and authorize the app:\n")
    print(auth_url)
    webbrowser.open(auth_url)

    # Step 2: User pastes the code returned in the redirect URL
    code = input("\nPaste the 'code' value from the redirected URL here: ").strip()
    # Step 3: Exchange the authorization code for an access token
    token = exchange_code_for_token(code, client_id, client_secret, redirect_uri)
    access_token = token['access_token']
    print(token)

    # Step 4: Use token to access Polar AccessLink API
    headers = {
        "Authorization": f"Bearer {access_token}"
    }

    response = requests.get("https://www.polaraccesslink.com/v3/users", headers=headers)
    print("\nAPI Response Status Code:", response.status_code)
    print(response.json())