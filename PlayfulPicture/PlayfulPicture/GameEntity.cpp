
#include "GameEntity.h"

namespace SDLFramework {


	GameEntity::GameEntity(float x, float y)
		: vPosition(x, y), rotation(0.0f), scale(Vec2_One), isActive(true), gameEntity(nullptr) {
	}

	GameEntity::GameEntity(const Vector2& position) : vPosition(position), rotation(0.0f), scale(Vec2_One), isActive(true), gameEntity(nullptr)
	{
	}


	GameEntity::~GameEntity() {
		gameEntity = nullptr;
	}

	void GameEntity::SetPosition(float x, float y)
	{
		vPosition = Vector2(x, y);
	}

	void GameEntity::Position(const Vector2& pos) {
		vPosition = pos;
	}

	Vector2 GameEntity::Position(Space space) {
		if (space == Local || gameEntity == nullptr) {
			return vPosition;
		}
		Vector2 parentScale = gameEntity->Scale(World);
		Vector2 rotPosition = RotateVector(vPosition, gameEntity->Rotation(Local));

		return gameEntity->Position(World) + Vector2(rotPosition.x * parentScale.x, rotPosition.y * parentScale.y);
	}

	void GameEntity::Rotation(float rot) {
		rotation = rot;

		while (rotation > 360.0f) {
			rotation -= 360.0f;
		}

		while (rotation < 0.0f) {
			rotation += 360.0f;
		}
	}

	float GameEntity::Rotation(Space space) {
		if (space == Local || gameEntity == nullptr) {
			return rotation;
		}

		return gameEntity->Rotation(World) + rotation;
	}

	void GameEntity::SetScale(Vector2 scale) {
		scale = scale;
	}

	Vector2 GameEntity::Scale(Space space) {
		if (space == Local || gameEntity == nullptr) {
			return scale;
		}

		Vector2 scale = gameEntity->Scale(World);
		scale.x *= scale.x;
		scale.y *= scale.y;

		return scale;
	}

	void GameEntity::Active(bool active) {
		isActive = active;
	}

	bool GameEntity::Active() const {
		return isActive;
	}

	void GameEntity::SetParent(GameEntity* parent) {
		if (parent == nullptr) {
			vPosition = Position(World);
			rotation = Rotation(World);
			scale = Scale(World);
		}
		else {
			if (gameEntity != nullptr) {
				SetParent(nullptr);
			}
			Vector2 parentScale = parent->Scale(World);

			vPosition = RotateVector(Position(World) - parent->Position(World), -parent->Rotation(World));
			vPosition.x /= parentScale.x;
			vPosition.y /= parentScale.y;

			rotation -= parent->Rotation(World);
			scale = Vector2(scale.x / parentScale.x, scale.y / parentScale.y);
		}

		gameEntity = parent;
	}

	GameEntity* GameEntity::Parent() const
	{
		return gameEntity;
	}

	void GameEntity::Translate(Vector2 vec, Space space) {
		if (space == World) {
			vPosition += vec;
		}
		else {
			vPosition += RotateVector(vec, Rotation());
		}
	}

	void GameEntity::Rotate(float amount) {
		Rotation(rotation + amount);
	}
}