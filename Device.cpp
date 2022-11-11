#include "Device.h"
#include <string>
void Device::init(unsigned int id, DeviceType type, std::string& os) 
{
	_active = false;
	_os = os;
	_type = type;
	_id = id;
}
std::string Device::getOS() const 
{
	return _os;
}
unsigned int Device::getID() const 
{
	return _id;
}
DeviceType Device::getType() const 
{
	return _type;
}