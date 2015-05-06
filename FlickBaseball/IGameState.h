#pragma once

namespace fbb {

class IGameState {
protected:
	virtual ~IGameState() {}
	virtual void init() {}
	virtual void draw() {}
	virtual void update() {}
};

} //End namespace