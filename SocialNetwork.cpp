#include "SocialNetwork.h"
#include "Device.h"
void SocialNetwork::init(std::string networkName, int minAge) {
	_NetworkName = networkName;
	_minAge = minAge;
	_profileList = new ProfileList;
	_profileList->init();
}
void SocialNetwork::clear() {
	_profileList->clear();
	delete _profileList;
}
std::string SocialNetwork::getNetworkName() const {
	return _NetworkName;
}
int SocialNetwork::getMinAge() const {
	return _minAge;
}
bool SocialNetwork::addProfile(const Profile& profile_to_add) {
	if (profile_to_add.getOwner().getAge()<_minAge)
	{
		return false;
	}
	_profileList->add(profile_to_add);
}
std::string SocialNetwork::getWindowsDevices()const {
	
	ProfileNode* curr = _profileList->get_first();
	std::string ret = "";
	while (curr)
	{
		User user = curr->get_data().getOwner();
		DeviceNode* deviceNode = user.getDevices().get_first();
		while (deviceNode)
		{
			Device device = deviceNode->get_data();
			std::string os = device.getOS();
			if (os == WINDOWS7 || os==WINDOWS10 || os== WINDOWS11 )
			{
				ret += "[" + device.getID() + ', ' + os + "], ";
			}
			deviceNode = deviceNode->get_next();
		}
		curr = curr->get_next();
	}
	return ret.substr(0,ret.length()-2);
}