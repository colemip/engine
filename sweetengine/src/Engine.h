#ifndef SWEET_ENGINE_H
#define SWEET_ENGINE_H

#include <string>

namespace Sweet
{
	class Engine
	{
	private:
		std::string version;
		static Sweet::Engine *instance;

	public:
		Engine();
		~Engine();
		void Init();
		void Update(double dt);
		void Render();
		void Run();
		void CleanUp();
		void Exit();
		void Message();
	};
}

#endif