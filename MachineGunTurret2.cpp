#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FireBullet2.hpp"
#include "Group.hpp"
#include "MachineGunTurret2.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int MachineGunTurret2::Price = 50;
MachineGunTurret2::MachineGunTurret2(float x, float y) :
	// TODO 2 (2/8): You can imitate the 2 files: 'MachineGunTurret.hpp', 'MachineGunTurret.cpp' to create a new turret. (ok)
	Turret("play/tower-base.png", "play/turret-4.png", x, y, 300, Price, 0.3) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurret2::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new FireBullet2(Position + normalized * 36, diff, rotation, this));
	AudioHelper::PlayAudio("big gun.wav");
}
