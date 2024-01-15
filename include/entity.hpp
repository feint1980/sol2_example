#pragma once

#ifndef PROGRAM_ENTITY_HPP
#define PROGRAM_ENTITY_HPP

#include <iostream>
#include "zm/vec3.hpp"

class entity {
private:
	zm::vec3 position_;

public:
	entity() {
		this->position_ = { 1, 1, 1 };
	}

	zm::vec3 get_position() const {
		std::cout << "get_position called \n";
		return this->position_;
	}
	void set_position(zm::vec3 v) {
		std::cout << "set_position called \n";
		this->position_ = v;
	}

	float get_position_y() const {
		std::cout << "get_position_y called \n";
		return this->position_.y;
	}

	void set_position_y(float y) {	
		std::cout << "set_position_y called \n";
		this->position_.y = y;
	}
};

#endif // PROGRAM_ENTITY_HPP
