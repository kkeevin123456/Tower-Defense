#ifndef MACHINEGUNTURRET2_HPP
#define MACHINEGUNTURRET2_HPP
#include "Turret.hpp"

class MachineGunTurret2: public Turret {
public:
	static const int Price;
    MachineGunTurret2(float x, float y);
	void CreateBullet() override;
};
#endif // MACHINEGUNTURRET2_HPP

