#include "AntiCheat_jump.h"
#include "CPlayer.h"

AntiCheat_jump::AntiCheat_jump(CPlayer* player) : AntiCheat(player)
{
}

bool AntiCheat_jump::HandleMovement(MovementInfo& MoveInfo, Opcodes opcode, bool cheat)
{
    AntiCheat::HandleMovement(MoveInfo, opcode, cheat);

    if (!Initialized())
        return false;

    if (!cheat && opcode == MSG_MOVE_JUMP && isFalling(oldMoveInfo))
    {
        const Position* p = storedMoveInfo.GetPos();
        m_Player->TeleportTo(storedMapID, p->x, p->y, p->z, p->o, TELE_TO_NOT_LEAVE_COMBAT);

        if (m_Player->GetSession()->GetSecurity() > SEC_PLAYER)
            m_Player->BoxChat << "Jump hack" << "\n";

        return SetOldMoveInfo(true);
    }

    if (opcode == MSG_MOVE_JUMP)
        SetStoredMoveInfo(false);

    return SetOldMoveInfo(false);
}
