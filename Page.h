#pragma once
#include "User.h"
class Page
{
private:
	std::string _status;
	std::string _posts;
public:
	void init();
	std::string getPosts();
	std::string getStatus();
	void clearPage();
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);
};

/*
* private:
	User _user;
	std::string _status;
public:
	void init(User owner);
	void clear();
	User getOwner()const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
*/