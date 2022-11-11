#include "Device.h"
#include <string>
void Device::init(unsigned int id, DeviceType type, const std::string& os)
{
	this->_active = true;
	this->_os = os;
	this->_type = type;
	this->_id = id;
}
std::string Device::getOS() const {
	return this->_os;
}
unsigned int Device::getID() const {
	return this->_id;
}
DeviceType Device::getType() const {
	return this->_type;
}
bool Device::isActive() const {
	return this->_active;
}
void Device::activate() {
	this->_active = true;
}
void Device::deactivate() {
	this->_active = false;
}