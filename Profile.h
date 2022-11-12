#pragma once
#include "UserList.h"
#include "Page.h"
#include "User.h"
#include <sstream>
#include <vector>
class Profile
{
private:
	User _user;
	Page* _page;
	UserList* _friends;
public:
	void init(const User& owner);
	void clear();
	User getOwner()const;
	void setStatus(const std::string& new_status);
	void addPostToProfilePage(const std::string& post);
	void addFriend(const User& friend_to_add);
	std::string getPage()const;
	std::string getFriends()const;
	std::string getFriendsWithSameNameLength()const;
	void changeAllWordsInStatus(const std::string& word);
	void changeWordInStatus(const std::string& word_to_replace,const std::string& new_word);
};
/*
* this is a custom function that splits strings
* strtok is not great and i dont like using it
*/
void split_str(std::string const& str, const char delim, std::vector <std::string>& out);
