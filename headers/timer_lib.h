typedef struct tm DataTime;

typedef struct{
	long long dd; //
	int hh; //
	int min; //
	int sec; //
	int nano; //
} Timer;

// Устанавливает текущее системное время данного компьютера
DataTime * setCurrentTime();

// Преобразует данную строку в формат DataTimer
DataTime * getTime(char*); // YY-MM-DD HH:MIN:SEC

// Печатает день недели (7-дневка, понедельник - 1 день)
char printWeekDay(DataTime*);

// Вычисляет значение DataTime через DD HH:MIN:SEC
DataTime * after(char*); // DD HH:MIN:SEC

// Вычисляет значение DataTime до DD HH:MIN:SEC
DataTime * before(char*); // DD HH:MIN:SEC

// Получает значение поле Timer через аргумент командной строки, введенный как YY-MM-DD HH:MIN:SEC
// Если аргумент отстутствует, все поля - 0
Timer * getTimer(long long dd, int hh, int min, int sec, int nano);

// Сложение показаний двух Timer
void addTm(Timer *, const Timer*);

// Вычитание
void minusTm(Timer *, const Timer*);

// печать полей в формате DD HH:MIN:SEC
void showTimer(const Timer*);

// сложение показаний Timer с DataTime
DataTime plusTimer(DataTime, const Timer*);

// Установка значений таймера для начала измерений времени исполнения кода программы
Timer startTime();

// Установка значений таймера конца измерений времени исполнения кода программы
Timer* stopTime(Timer*);