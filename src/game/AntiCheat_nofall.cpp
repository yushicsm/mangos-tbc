#include "AntiCheat_nofall.h"
#include "CPlayer.h"
#include "World.h"

AntiCheat_nofall::AntiCheat_nofall(CPlayer* player) : AntiCheat(player)
{
}

bool AntiCheat_nofall::HandleMovement(MovementInfo& moveInfo, Opcodes opcode, bool cheat)
{
    AntiCheat::HandleMovement(moveInfo, opcode, cheat);

    if (!Initialized())
        return false;

    if (newMoveInfo.HasMovementFlag(MOVEFLAG_LEVITATING))
    {
        if (m_Player->GetSession()->GetSecurity() > SEC_PLAYER)
            m_Player->BoxChat << "NOFALL CHEAT" << "\n";

        const Position* p = oldMoveInfo.GetPos();

        m_Player->TeleportTo(oldMapID, p->x, p->y, p->z, p->o, TELE_TO_NOT_LEAVE_COMBAT);

        return true;
    }

    return SetOldMoveInfo(false);
}
