#pragma once
#include "DeviceList.h"
#include <string>
class User
{
private:
	DevicesList* _devicelist;
	std::string _username;
	unsigned int _id;
	unsigned int _age;
public:
	void init(unsigned int id,std::string username, unsigned int age);
	void clear();
	unsigned int getAge()const;
	unsigned int getID()const;
	std::string getUsername()const;
	DevicesList& getDeviceList()const;
	void AddDevice(const Device& device);
	bool checkIfDevicesAreOn()const;
};

