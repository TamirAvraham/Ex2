#include "Profile.h"
#include <iostream>
#include <vector>
#include <sstream>
void split_str(std::string const& str, const char delim,std::vector <std::string>& out)
{
	  
	std::stringstream s(str);

	std::string s2;
	while (std::getline(s, s2, delim))
	{
		out.push_back(s2); 
	}
}

void Profile::init(const User& owner)
{
	this->_user = owner;
	_page = new Page;
	_page->init();
	_friends = new UserList;
	_friends->init();
}
void Profile::clear() 
{
	_page->clearPage();
	_friends->clear();
	delete _page;
	delete _friends;
}
User Profile::getOwner()const {
	return _user;
}
void Profile::setStatus(const std::string& new_status) {
	_page->setStatus(new_status);
}
void Profile::addPostToProfilePage(const std::string& post) {
	_page->addLineToPosts(post);
}
void Profile::addFriend(const User& friend_to_add) {
	_friends->add(friend_to_add);
}

std::string Profile::getPage()const {
	return "Status: " + _page->getStatus() +"\n*******************\n*******************\n" + _page->getPosts();
		
}
std::string Profile::getFriends()const
{
	UserNode* copy = _friends->get_first();
	std::string ret = "";
	while (copy)
	{
		ret += copy->get_data().getUserName()+",";
		copy = copy->get_next();
	}
	
	return ret.substr(0,ret.length() - 1);
}
std::string Profile::getFriendsWithSameNameLength()const {
	std::vector<std::string> namesVec;
	int ownerNameLength = _user.getUserName().length();
	std::string ret="";
	namesVec.begin();
	split_str(this->getFriends(), ',', namesVec);
	for(auto i=namesVec.cbegin();i!=namesVec.cend();++i )
	{
		if (i._Ptr->length()==ownerNameLength)
		{
			ret += i._Ptr->c_str();
			ret += ',';
		}
	}
	return ret.substr(0, ret.length() - 1);
}

void Profile::changeAllWordsInStatus(const std::string& word)
{
	std::string stat = _page->getStatus();
	std::string ret = "";
	for (int i = 0; i < stat.length(); i++)
	{
		char curr = stat[i];
		char next = stat[i+1];
		bool IsChar = curr != ' ' && curr != ' \t' && curr != '\n' && i < word.length() - 1;
		if (IsChar && i < word.length() - 1)
		{
			if (next == ' ' || next == '\t' || next == '\n')
			{
				ret += word;
			}
			
		}
		else if (IsChar && i == word.length() - 1)
		{
			ret += word;
		}
		else if(curr == ' ' || curr == '\t' || curr == '\n')
		{
			ret += curr;
		}
		
	}
	_page->setStatus(ret);
}
void Profile::changeWordInStatus(const std::string& word_to_replace, const std::string& new_word)
{
	int i = 0;
	std::string& status = _page->getStatus();
	while ((i=status.find(word_to_replace))!=std::string::npos)
	{
		status.replace(i, word_to_replace.length(), new_word);
	}
	

}
