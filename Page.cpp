#include "Page.h"

void Page::init() {
	_posts = "";
}
std::string& Page::getPosts() {
	return _posts;
}
std::string& Page::getStatus() {
	return _status;
}
void Page::clearPage() {
	_posts = "";
}
void Page::setStatus(const std::string& status) {
	_status = status;
}
void Page::addLineToPosts(const std::string& new_line){
	_posts += new_line + "\n";
}