class GameEvent
{
public:
    virtual ~GameEvent() = default;
    virtual void triggerEvent() = 0;  // Метод для срабатывания события
};
