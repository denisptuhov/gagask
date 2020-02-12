#pragma once
#include <memory>
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include "Resourses.h"

using namespace resourses;

struct Field
{

	Field(size_t new_length = 50, size_t new_width = 50) : length(new_length), width(new_width)
	{
		std::shared_ptr<std::shared_ptr<fieldElement[]>[]> new_fld(new std::shared_ptr<fieldElement[]>[width], std::default_delete<std::shared_ptr<fieldElement[]>[]>());
		for (size_t i = 0; i < width; ++i)
		{
			std::shared_ptr<fieldElement[]> new_elem(new fieldElement[length], std::default_delete<fieldElement[]>());
			new_fld[i] = new_elem;
		}

		fld = new_fld;
	}

	void swap(Field& other)
	{
		std::swap(units_cnt, other.units_cnt);
		std::swap(length, other.length);
		std::swap(width, other.width);
		std::swap(fld, other.fld);
	}

	Field(Field const& other)
	{
		units_cnt = other.units_cnt;
		length = other.length;
		width = other.width;
		fld = other.fld;
	}

	Field& operator=(Field const& other)
	{
		if (&other != this)
		{
			Field(other).swap(*this);
		}
		return *this;
	}

	Field& operator=(Field&& other)
	{
		swap(other);
		return *this;
	}

	Field(Field&& other)
	{
		swap(other);
	}

	~Field() = default;

	returnCode addUnit(size_t i, size_t j, unitTypes unitType)
	{
		if (fld[i][j].unitType == unitTypes::noUnit)
			return returnCode::uncorrectPlacement;

		++units_cnt;
		fld[i][j].unitType = unitType;
		return returnCode::correntPlacement;
	}

	returnCode deleteUnit(size_t i, size_t j, unitTypes unitType)
	{
		if (fld[i][j].unitType == unitTypes::noUnit)
			return returnCode::uncorrectPlacement;

		--units_cnt;
		fld[i][j].unitType = unitType;
		return returnCode::correntPlacement;
	}

	void show()
	{
		for (size_t j = 0; j < length; ++j)
		{
			std::cout << "  - ";
		}
		std::cout << "\n";

		for (size_t i = 0; i < width; ++i)
		{
			for (size_t j = 0; j < length; ++j)
			{
				std::cout << "| " << static_cast<char>(fld[i][j].terType) << " ";
			}
			std::cout << "|" << "\n";
			for (size_t j = 0; j < length; ++j)
			{
				std::cout << "  - ";
			}
			std::cout << "\n";
		}
	}

private:
	struct fieldElement
	{
		fieldParams terType = fieldParams::grass;
		unitTypes unitType = unitTypes::noUnit;
	};

	size_t units_cnt = 0;
	size_t length = 0;
	size_t width = 0;
	std::shared_ptr<std::shared_ptr<fieldElement[]>[]> fld;
};