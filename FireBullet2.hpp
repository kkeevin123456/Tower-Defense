#ifndef FIREBULLET2_HPP
#define FIREBULLET2_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class FireBullet2 : public Bullet {
public:
	explicit FireBullet2(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // FIREBULLET2_HPP

