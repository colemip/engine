#ifndef SWEET_ENGINE_H
#define SWEET_ENGINE_H

#include <string>

namespace Sweet
{
	class Engine
	{
	private:
		std::string version;
	public:
		Engine();
		~Engine();
		void Init();
		void Update();
		void Render();
		void Run();
		

	};
}

#endif