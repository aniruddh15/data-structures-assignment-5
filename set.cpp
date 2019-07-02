//Assignment 5
//Author: Aniruddh Kathiriya

#include "set.h"
#include <iostream>
#include <cassert>
#include <algorithm>

set::set(){
	head=NULL;
	used=0;
}
set::~set(){
	list_clear(head);
	used=0;
	
}

set::set (const set& source){
	node *tail_ptr;
	list_copy(source.head, head, tail_ptr);
	used=source.used;
}
set& set::operator = (const set& source){
	if(this==&source){
		return *this;
	}
	node *tail_ptr;
	list_clear(head);
	used=source.used;
	list_copy(source.head,head,tail_ptr);
	return *this;
}
void set::insert(const value_type& entry){
	if(!(contains(entry))){
		
		list_head_insert(head,entry);
		used++;	
	}
}
void set::remove(const value_type& entry){
	if(used!=0){
		if(used==1){
			if(head->data()==entry){
			list_head_remove(head);
			}
		}else{
			node *prv_ptr=head;
			for(node *temp=head->link();temp!=NULL;temp=temp->link()){
				if(temp->data()==entry){
				list_remove(prv_ptr);
				break;
				}
			prv_ptr=temp;
			}
		}
	used--;
	}
}
set::size_type set::size() const{
	return used;
}
bool set::contains (const value_type& entry) const{
	return list_search(head,entry)!=NULL;
}
set set_union (const set& s1, const set& s2){
	set s3;
	
	for(const node* temp_s1=s1.head;temp_s1!=NULL;temp_s1=temp_s1->link()){
		s3.insert(temp_s1->data());
	}
	for(const node* temp_s2=s2.head;temp_s2!=NULL;temp_s2=temp_s2->link()){
		s3.insert(temp_s2->data());
	}
	return s3;
}
set set_intersection(const set& s1, const set& s2){
	set s3;
	for(const node* temp_s1=s1.head;temp_s1!=NULL;temp_s1=temp_s1->link()){
		if(s2.contains(temp_s1->data())){
			s3.insert(temp_s1->data());
		}
	}
	return s3;
}
set set_difference (const set& s1, const set& s2){
	set s3;
		for(const node* temp_s1=s1.head;temp_s1!=NULL;temp_s1=temp_s1->link()){
			if(!(s2.contains(temp_s1->data()))){
				s3.insert(temp_s1->data());
			}
		}
	return s3;
}
bool is_subset (const set& s1, const set& s2){
	for(const node* temp_s1=s1.head;temp_s1!=NULL;temp_s1=temp_s1->link()){
		if(!(s2.contains(temp_s1->data()))){
			return false;
		}
	}
	return true;
}
bool operator == (const set& s1, const set& s2){
	if(s1.size()!=s2.size()){
		return false;
	}
	return is_subset(s1,s2);
}
std::ostream& operator << (std::ostream& output, const set& s){
	for(node *temp=s.head;temp!=NULL;temp=temp->link()){
		output<<temp->data()<<" ";
	}
	return output;
}