#pragma once
#include <string>
#include "ProfileList.h"
class SocialNetwork
{
private:
	std::string _NetworkName;
	int _minAge;
	ProfileList _profileList;
public:
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName();
	int getMinAge();
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices();
};

