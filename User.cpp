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
std::string User::getUsername()const {
	return _username;
}
DevicesList& User::getDeviceList()const{
	return (DevicesList&)_devicelist;
}
void User::AddDevice(const Device& device){
	_devicelist->add(device);
}