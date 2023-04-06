#pragma once
#include <initializer_list>
#include <string>

/**
* \brief Класс двусвязный линейный список для хранения целых чисел
*/
class DLS
{
public:
	/**
	* \brief Конструктор по-умолчанию
	*/
	DLS();
	/**
	* \brief Создание объекта из последовательности
	*/
	DLS(const std::initializer_list<int> values);
	/**
	* \brief Деструктор по-умолчанию
	*/
	~DLS();
	/**
	* \brief Функция добавления элементов
	* \param pos целое число. Позиция элемента в списке
	* \param value целое число
	*/
	void AddElement(const int pos, const int value);
	/**
	* \brief Функция добавления элемента в начало
	* \param value целое число
	*/
	void AddElementHead(const int value);
	/**
	* \brief Функция добавления элемента в конец
	* \param value целое число
	*/
	void AddElementTail(const int value);
	/**
	* \brief Функция удаления элемента
	* \param pos целое число. Позиция элемента в списке
	*/
	void RemoveElement(int pos);
	/**
	* \brief Функция получения элемента
	* \param pos целое число > 0. Позиция элемента в списке
	*/
	const int GetElement(const int pos);
	/**
	* \brief Функция получения всех элементов в виде строки
	*/
	const std::string ToString();
	/**
	* \brief Функция проверки на пустоту.
	*/
	const bool IsEmpty();
	/**
	* \brief Функция получения размера.
	*/
	std::size_t GetSize() const;

private:
	/**
	* \brief Элементы ДЭК для хранения целых чисел
	*/
	class DLSElement
	{
	public:
		/**
		* \brief Конструктор с параметрами
		* \param value хранящееся значение 
		* \param next указатель на следующий элемент
		* \param prev указатель на предыдущий элемент
		*/
		DLSElement(int value, DLSElement* next = nullptr, DLSElement* prev = nullptr);
		/**
		* \brief значение элемента
		*/
		int value;
		/**
		* \brief Указатель на следующий элемент
		*/
		DLSElement* next;
		/**
		* \brief Указатель на предыдущий элемент
		*/
		DLSElement* prev;
	};
	/**
	* \brief размер списка
	*/
	size_t size;

	DLS(const DLS& rhs);
	/**
	* \brief Указатель на голову
	*/
	DLSElement* head;
	/**
	* \brief Указатель на хвост
	*/
	DLSElement* tail;

	DLS operator= (const DLS& rhs) = delete;
	DLS operator> (const DLS& rhs) = delete;
	DLS operator< (const DLS& rhs) = delete;
	DLS operator>= (const DLS& rhs) = delete;
	DLS operator<= (const DLS& rhs) = delete;
	DLS operator!= (const DLS& rhs) = delete;
	DLS operator== (const DLS& rhs) = delete;
};
