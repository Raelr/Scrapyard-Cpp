#ifndef LAYER_H
#define LAYER_H

#include "Core.h"
#include "Events/Event.h"

namespace Scrapyard {

    class Layer {

        public: 
            Layer(const std::string& name = "Layer");
            virtual ~Layer();
            virtual void onAttach();
            virtual void onDetach();
            virtual void onUpdate();
            virtual void onEvent(Event& event) {}

            inline const std::string& getName() const { return m_debugName}
        protected:
            std::string m_debugName;
    };
}

#endif