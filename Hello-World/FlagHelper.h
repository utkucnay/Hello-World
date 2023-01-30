#pragma once

class FlagHelper {
public:
	template<typename T>
	static bool IsFlag(T in, T flag) {
		return (in & flag) == flag;
	}
};