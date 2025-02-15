#ifndef WARRIOR_H
#define WARRIOR_H

#include "Role.h"
#include <iostream>

class Warrior : public Role {
public:
    Warrior() : Role("战士", 200, 50, 20, 25) {}

    void skill(Role& target) override {
        if (getMana() < getSkillCost()) {
            std::cout << "蓝量不足，无法使用技能！" << std::endl;
            return;
        }
        Role::skill(target);
        std::cout << getName() << " 使用技能攻击 " << target.getName() << "!" << std::endl;
        target.setHP(target.getHP() - 40);
    }
     void ultimate(Role& target) override {
    if (getCountRound() < 3) {
        std::cout << "大招无法现在使用，请在第3回合之后释放!" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "大招已经被使用了!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " 使用大招!" << std::endl;
        target.setMana(0);
        setCountUlt(1);
    }
}
};

#endif
