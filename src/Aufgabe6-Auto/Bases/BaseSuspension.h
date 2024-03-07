//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BASESUSPENSION_H
#define RAYLIBSTARTER_BASESUSPENSION_H


namespace console::car::base::components
{

    class BaseSuspension
    {
    public:
        BaseSuspension(float brainDamageDamping);
        virtual float getBrainDamageDamping();
    protected:
        float brainDamageDamping_;
    private:
        BaseSuspension() = delete;
    };

}

#endif //RAYLIBSTARTER_BASESUSPENSION_H
