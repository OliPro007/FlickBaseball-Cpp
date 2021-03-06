////////////////////////////////////////////////////////////
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//
// This file is modified from the original version
// of Overdrivr on SFML github wiki
// Original file: https://github.com/SFML/SFML/wiki/Source:-Draw-Rounded-Rectangle
//
////////////////////////////////////////////////////////////

#include "RoundRectangle.h"
#include <cmath>

namespace fbb {
	RoundRectangle::RoundRectangle(const sf::Vector2f& size, float radius, unsigned int cornerPointCount) {
		this->size = size;
		this->radius = radius;
		this->cornerPointCount = cornerPointCount;
		update();
	}

	void RoundRectangle::setSize(const sf::Vector2f& size) {
		this->size = size;
		update();
	}

	const sf::Vector2f& RoundRectangle::getSize() const {
		return size;
	}

	void RoundRectangle::setCornersRadius(float radius) {
		this->radius = radius;
		update();
	}

	const float RoundRectangle::getCornersRadius() const {
		return radius;
	}

	void RoundRectangle::setCornerPointCount(unsigned int count) {
		this->cornerPointCount = count;
		update();
	}

	std::size_t RoundRectangle::getPointCount() const {
		return cornerPointCount * 4;
	}

	sf::Vector2f RoundRectangle::getPoint(std::size_t index) const {
		if(index >= cornerPointCount * 4)
			return sf::Vector2f(0, 0);

		float deltaAngle = 90.0f / (cornerPointCount - 1);
		sf::Vector2f center;
		unsigned int centerIndex = index / cornerPointCount;
		unsigned int offset = 0;
		static const float pi = 3.141592654f;

		switch(centerIndex) {
			case 0: center.x = size.x - radius; center.y = radius; break;
			case 1: center.x = radius; center.y = radius; break;
			case 2: center.x = radius; center.y = size.y - radius; break;
			case 3: center.x = size.x - radius; center.y = size.y - radius; break;
		}

		return sf::Vector2f(radius*cos(deltaAngle*(index - centerIndex)*pi / 180) + center.x,
							-radius*sin(deltaAngle*(index - centerIndex)*pi / 180) + center.y);
	}
}//namespace sf