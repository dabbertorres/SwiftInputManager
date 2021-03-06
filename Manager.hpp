#ifndef DBR_INPUT_MANAGER_HPP
#define DBR_INPUT_MANAGER_HPP

#include <map>
#include <string>
#include <functional>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Binding.hpp"

namespace dbr
{
	namespace input
	{
		template<typename T>
		class Manager
		{
			public:
				using BindingType = Binding<T>;

				void add(T input, const typename BindingType::Callback& f, bool onPress = false)
				{
					bindings.emplace_back(input, f, onPress);
				}

				void operator()(const sf::Event& e)
				{
					for(auto& k : bindings)
					{
						k(e);
					}
				}

			private:
				std::vector<BindingType> bindings;
		};
	}
}

#endif // KEYBOARDMANAGER_HPP
