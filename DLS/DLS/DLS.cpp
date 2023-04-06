#include "DLS.h"
#include <stdexcept>

DLS::DLS() : size(0), head(nullptr), tail(nullptr) {}

DLS::DLS(const std::initializer_list<int> values) : DLS()
{
	for (const auto n : values) {
		AddElementTail(n);
	}
}

DLS::~DLS()
{
	while (this->GetSize() > 0)
	{
		RemoveElement(1);
	}
}

void DLS::AddElement(const int pos, const int value)
{
	if (pos <= 0) throw std::out_of_range("Позиция не должна быть отрицательной или равнятся 0");
	else
	{
		auto temp = new DLSElement{ value, nullptr, nullptr };
		if (this->IsEmpty() or pos == 1)
		{
			AddElementHead(value);
		}
		else if (pos >= this->size)
		{
			AddElementTail(value);
		}
		else 
		{
			auto itemNext = this->head;
			for (size_t i = 0; i < pos - 1; i++)
			{
				itemNext = itemNext->next;
			}
			itemNext->next->prev = temp;
			temp->next = itemNext->next;
			temp->prev = itemNext;
			itemNext->next = temp;
			this->size++;
		}
	}
}

void DLS::AddElementHead(const int value)
{
	auto temp = new DLSElement{ value, nullptr, nullptr };
	if (this->IsEmpty()) {
		this->head = this->tail = temp;
	}
	else
	{
		temp->next = this->head;
		this->head->prev = temp;
		this->head = temp;
	}
	this->size++;
}

void DLS::AddElementTail(const int value)
{
	auto temp = new DLSElement{ value, nullptr, nullptr };
	if (this->IsEmpty()) {
		this->head = this->tail = temp;
	}
	else
	{
		this->tail->next = temp;
		temp->prev = this->tail;
		this->tail = temp;
	}
	this->size++;
}

void DLS::RemoveElement(int pos)
{
	if (pos <= 0) throw std::out_of_range("Позиция не должна быть отрицательной или равнятся 0");
	else if (pos > this->GetSize()) throw std::out_of_range("Позиция не должна быть больше размера списка");
	else
	{
		auto item = this->head;
		for (size_t i = 0; i < pos-1; i++)
		{
			item = item->next;
		}
		if (this->tail == item and this->head==item)
		{
			this->head = this->tail = nullptr;
		}
		else if (item == this->tail)
		{
			this->tail = this->tail->prev;
			this->tail->next = nullptr;
		}
		else if (item == this->head)
		{
			this->head = this->head->next;
			this->head->prev = nullptr;
		}
		else
		{
			item->prev->next = item->next;
			item->next->prev = item->prev;
		}
		delete item;
		this->size--;
	}
}

const int DLS::GetElement(const int pos)
{
	if (pos < 0) throw std::out_of_range("Число должно быть больше 0");
	else if (pos > this->GetSize()) throw std::out_of_range("Число должно быть в пределах размера списка");
	else 
	{
		auto item = this->head;
		for (size_t i = 0; i < pos-1; i++)
		{
			item = item->next;
		}
		return item->value;
	}
}

const std::string DLS::ToString()
{
	std::string output = "";
	auto item = this->head;
	for (size_t i = 0; i < this->GetSize(); i++)
	{
		output += std::to_string(item->value);
		item = item->next;
		if (item) output += ", ";
	}
	return output;
}

const bool DLS::IsEmpty()
{
	return this->size == 0;
}

std::size_t DLS::GetSize() const
{
	return this->size;
}

DLS::DLSElement::DLSElement(int value, DLSElement* next, DLSElement* prev) : value(value), next(next), prev(prev) {}
