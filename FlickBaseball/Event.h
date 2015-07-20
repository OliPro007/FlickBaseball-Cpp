#pragma once
#include <SFML\Window.hpp>

namespace fbb {

class Event {
public:
	struct ChangeStateEvent {
		BYTE thisState;
		BYTE nextState;
	};

	enum EventType {
		Close,
		ChangeState,
		Return,

		Count
	};
	EventType type;

	union {
		ChangeStateEvent changeState;
	};

};

} //End namespace