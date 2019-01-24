#pragma once

#include "build.h"

namespace wiw {
	namespace build {
		class Material {
		public:
			Material();
			~Material();

			void setAmbient(VECTOR4D color) const;
			void setDiffuse(VECTOR4D color) const;
			void setSpecular(VECTOR4D color) const;
			void setShininess(GLfloat arg) const;
			void setEmission(VECTOR4D color) const;
		};
	}
}