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
	* \param pos целое число
	*/
	void RemoveElement(int pos);
	/**
	* \brief Функция получения элемента
	* \param pos целое число > 0
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
		* \param value Целое значение.
		*/
		DLSElement(int value, DLSElement* next = nullptr, DLSElement* prev = nullptr);
		~DLSElement();

		int value;
		DLSElement* next;
		DLSElement* prev;
	};
	size_t size;

	DLS(const DLS& rhs);
	DLSElement* head;
	DLSElement* tail;

	DLS operator= (const DLS& rhs) = delete;
};
