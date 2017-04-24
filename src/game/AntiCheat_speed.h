#pragma once

#include "AntiCheat.h"

class AntiCheat_speed : public AntiCheat
{
public:
    AntiCheat_speed(CPlayer* player);

    bool HandleMovement(MovementInfo& MoveInfo, Opcodes opcode, bool cheat) override;
    void HandleKnockBack(float angle, float horizontalSpeed, float verticalSpeed) override;
    void UpdateFlySpeed();
    float GetAllowedSpeed();
    float GetFlySpeed() { return m_FlySpeed; }
    float GetKnockBackSpeed() { return m_KnockbackSpeed; }

private:
    bool m_Knockback;
    float m_KnockbackSpeed;
    float m_FlySpeed;
};
