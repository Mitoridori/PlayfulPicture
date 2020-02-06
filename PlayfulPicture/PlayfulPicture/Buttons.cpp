#include "Buttons.h"

Buttons::Buttons()
{
}

Buttons::~Buttons()
{
}

bool Buttons::ContainsPoint(Texture* texture, int x, int y)
{
	if (texture) {
		if ((x > texture->Position().x - texture->GetWidth() * 0.5f) && (x < texture->Position().x + texture->GetWidth() * 0.5f)
			&& (y > texture->Position().y - texture->GetHeight() * 0.5f) && (y < texture->Position().y + texture->GetHeight() * 0.5f)) {
			return true;
		}
	}

	return false;
}
