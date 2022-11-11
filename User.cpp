#include "User.h"
void User::init(unsigned int id, std::string username, unsigned int age) {
	_id = id;
	_username = username;
	_age = age;
	_devicelist = new DevicesList;
	_devicelist->init();
}
void User::clear() {
	_devicelist->clear();
	delete _devicelist;
	_username = "";
	_age = 0;
	_id = 0;
}
unsigned int User::getAge()const{
	return _age;
}
unsigned int User::getID()const{
	return _id;
}
std::string User::getUserName()const {
	return _username;
}
DevicesList& User::getDevices()const{
	return *_devicelist;
}
void User::addDevice(const Device& device){
	_devicelist->add(device);
}
bool User::checkIfDevicesAreOn()const {
	
	DeviceNode* copy = _devicelist->get_first();
	while (copy) {
		
		if (!(copy->get_data().isActive()))
		{
			return false;
		}
		copy = copy->get_next();
	}
	return true;
}