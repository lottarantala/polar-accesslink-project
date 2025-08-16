# Polar Accesslink Project
Going to try to read my Polar data using Polar accesslink API: [https://www.polar.com/accesslink-api/#polar-accesslink-api](https://www.polar.com/accesslink-api/#polar-accesslink-api)
Don't know what this is going to be yet.

### How to compile:
```
mkdir build
cd build
cmake .. -G Ninja
ninja polar-accesslink-project
./polar-accesslink-project
```

* Note: You will need your own accesslink client to fill the information in **accesslink_information.json**. The structure is like so:
```
{
    "client_id": "",
    "client_secret": "",
    "redirect_uri": ""
}
```