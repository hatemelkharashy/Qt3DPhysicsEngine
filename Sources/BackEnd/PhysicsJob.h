#ifndef PHYSICSJOB_H
#define PHYSICSJOB_H
#include <Qt3DCore/QAspectJob>

class PhysicsAspect;
class PhysicsJob : public Qt3DCore::QAspectJob
{
public:
    PhysicsJob(PhysicsAspect* aspect);
    void setDeltaTime(qint64 dt);
    void run() override;

private:
    PhysicsAspect* mAspect;
    qint64 mdt;
};

#endif // PHYSICSJOB_H
