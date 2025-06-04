import json

def read_accesslink_info(filepath:str) -> dict:
    with open(filepath, 'r') as f:
        info = json.load(f)
    return info

if __name__=="__main__":
    accesslink_info = read_accesslink_info('accesslink_information.json')
    print(accesslink_info)