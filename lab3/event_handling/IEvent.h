class IEvent {
public:
    virtual void trigger() = 0; // Чисто виртуальная функция для срабатывания события
    virtual ~IEvent() = default; // Деструктор по умолчанию
};
