#pragma once

#include "AntiCheat.h"

class AntiCheat_jump : public AntiCheat
{
public:
    AntiCheat_jump(CPlayer* player);

    bool HandleMovement(MovementInfo& MoveInfo, Opcodes opcode, bool cheat) override;
};
