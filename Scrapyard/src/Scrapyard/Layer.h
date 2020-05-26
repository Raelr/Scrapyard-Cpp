#ifndef LAYER_H
#define LAYER_H

#include "Core.h"
#include "Events/Event.h"

namespace Scrapyard {

    // A basic layer in the LayerStack. 
    class Layer {
        public: 
            Layer(const std::string& name = "Layer");
            virtual ~Layer();
            // Actions which would be done when the layer is attached/detached from the layer. 
            virtual void onAttach();
            virtual void onDetach();
            // What happens when the layer is updated (every frame)
            virtual void onUpdate();
            // How the layer handles events.
            virtual void onEvent(Event& event) {}
            // A debug string - only used for debugging purposes.
            inline const std::string& getName() const { return m_debugName}
        protected:
            std::string m_debugName;
    };
}

#endif