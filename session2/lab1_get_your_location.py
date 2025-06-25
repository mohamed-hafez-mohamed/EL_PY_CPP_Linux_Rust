"""Write a Python program to get info about your location."""

import requests


def get_info_location():
    """Write your solution here. Don't forget to return the result at the end."""

    ip: dict = requests.get("https://api.ipify.org?format=json", timeout=10).json()
    ip = ip.get("ip", "")
    if not ip:
        raise ValueError("Could not retrieve IP address.")
    url = requests.get(f"https://ipinfo.io/{ip}/geo", timeout=10)
    return url.json()


if __name__ == "__main__":
    location_info = get_info_location()
    assert "ip" in location_info, "Test case failed"
    assert "city" in location_info, "Test case failed"
    assert "region" in location_info, "Test case failed"
    assert "country" in location_info, "Test case failed"
    assert "loc" in location_info, "Test case failed"
    assert "org" in location_info, "Test case failed"
