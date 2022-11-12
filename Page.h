#pragma once
#include "User.h"
class Page
{
private:
	std::string _status;
	std::string _posts;
public:
	void init();
	std::string& getPosts();
	std::string& getStatus();
	void clearPage();
	void setStatus(const std::string& status);
	void addLineToPosts(const std::string& new_line);
};

