/*==============================================================================
//  KeyNotationConversions.hpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2016/02/22
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Converts between Musical, Camelot, and OpenKey Formats
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

 
#ifndef KEYNOTATIONCONVERSIONS_H_INCLUDED
#define KEYNOTATIONCONVERSIONS_H_INCLUDED
#include <JuceHeader.h>
#include "../libKeyFinder/constants.h"

using KeyFinder::key_t;

/// <summary>
/// Static methods for converting detected keys between Camelot/OpenKey/Musical
/// </summary>
class KeyNotationConversions
{
public:
/*
	enum MusicalKey
	{
		A_MAJOR = 0,
		A_MINOR,
		B_FLAT_MAJOR,
		B_FLAT_MINOR,
		B_MAJOR,
		B_MINOR = 5,
		C_MAJOR,
		C_MINOR,
		D_FLAT_MAJOR,
		D_FLAT_MINOR,
		D_MAJOR = 10,
		D_MINOR,
		E_FLAT_MAJOR,
		E_FLAT_MINOR,
		E_MAJOR,
		E_MINOR = 15,
		F_MAJOR,
		F_MINOR,
		G_FLAT_MAJOR,
		G_FLAT_MINOR,
		G_MAJOR = 20,
		G_MINOR,
		A_FLAT_MAJOR,
		A_FLAT_MINOR,
		SILENCE = 24,
		UNANALYZED = 25
	};*/

	/// <summary>Returns Camelot key string representation of input detected key</summary>
	/// <param name="inKey">Key to be converted to Camelot</param>
	/// <returns>String containing Camelot Key</returns>
	static std::string getCamelotKeyFromKeyT(key_t inKey)
	{
		switch (inKey)
		{
			case key_t::A_MAJOR:
				return "11B";
				break;
			case key_t::A_MINOR:
				return "8A";
				break;
			case key_t::B_FLAT_MAJOR:
				return "6B";
				break;
			case key_t::B_FLAT_MINOR:
				return "3A";
				break;
			case key_t::B_MAJOR:
				return "1B";
				break;
			case key_t::B_MINOR:
				return "10A";
				break;
			case key_t::C_MAJOR:
				return "8B";
				break;
			case key_t::C_MINOR:
				return "5A";
				break;
			case key_t::D_FLAT_MAJOR:
				return "3B";
				break;
			case key_t::D_FLAT_MINOR:
				return "12A";
				break;
			case key_t::D_MAJOR:
				return "10B";
				break;
			case key_t::D_MINOR:
				return "7A";
				break;
			case key_t::E_FLAT_MAJOR:
				return "5B";
				break;
			case key_t::E_FLAT_MINOR:
				return "2A";
				break;
			case key_t::E_MAJOR:
				return "12B";
				break;
			case key_t::E_MINOR:
				return "9A";
				break;
			case key_t::F_MAJOR:
				return "7B";
				break;
			case key_t::F_MINOR:
				return "4A";
				break;
			case key_t::G_FLAT_MAJOR:
				return "2B";
				break;
			case key_t::G_FLAT_MINOR:
				return "11A";
				break;
			case key_t::G_MAJOR:
				return "9B";
				break;
			case key_t::G_MINOR:
				return "6A";
				break;
			case key_t::A_FLAT_MAJOR:
				return "4B";
				break;
			case key_t::A_FLAT_MINOR:
				return "1A";
				break;
			case key_t::SILENCE:
				return "SIL";
				break;
			case key_t::UNANALYZED:
				return "NON";
				break;
			default:
				return "ERR";
				break;
		}
	}

	/// <summary>Returns OpenKey key string representation of input detected key</summary>
	/// <param name="inKey">Key to be converted to OpenKey</param>
	/// <returns>String containing OpenKey</returns>
	static std::string getOpenKeyFromKeyT(KeyFinder::key_t inKey)
	{
		switch (inKey)
		{
			case key_t::A_MAJOR:
				return "4d";
				break;
			case key_t::A_MINOR:
				return "1m";
				break;
			case key_t::B_FLAT_MAJOR:
				return "11d";
				break;
			case key_t::B_FLAT_MINOR:
				return "8m";
				break;
			case key_t::B_MAJOR:
				return "6d";
				break;
			case key_t::B_MINOR:
				return "3m";
				break;
			case key_t::C_MAJOR:
				return "1d";
				break;
			case key_t::C_MINOR:
				return "10m";
				break;
			case key_t::D_FLAT_MAJOR:
				return "8d";
				break;
			case key_t::D_FLAT_MINOR:
				return "7m";
				break;
			case key_t::D_MAJOR:
				return "3d";
				break;
			case key_t::D_MINOR:
				return "12m";
				break;
			case key_t::E_FLAT_MAJOR:
				return "10d";
				break;
			case key_t::E_FLAT_MINOR:
				return "7m";
				break;
			case key_t::E_MAJOR:
				return "5d";
				break;
			case key_t::E_MINOR:
				return "2m";
				break;
			case key_t::F_MAJOR:
				return "12d";
				break;
			case key_t::F_MINOR:
				return "9m";
				break;
			case key_t::G_FLAT_MAJOR:
				return "7d";
				break;
			case key_t::G_FLAT_MINOR:
				return "6m";
				break;
			case key_t::G_MAJOR:
				return "2d";
				break;
			case key_t::G_MINOR:
				return "11m";
				break;
			case key_t::A_FLAT_MAJOR:
				return "9d";
				break;
			case key_t::A_FLAT_MINOR:
				return "6m";
				break;
			case key_t::SILENCE:
				return "SIL";
				break;
			case key_t::UNANALYZED:
				return "NON";
				break;
			default:
				return "ERR";
				break;
		}
	}

	/// <summary>Returns Standard Music Key string representation of input detected key</summary>
	/// <param name="inKey">Key to be converted to Musical Representation</param>
	/// <returns>String containing Musical Key</returns>
	static std::string getMusicalKeyFromKeyT(key_t keyEnum)
	{
		std::string result;
		switch (keyEnum)
		{
			case key_t::A_MAJOR:
				result = "A Major";
				break;
			case key_t::A_MINOR:
				result = "A Minor";
				break;
			case key_t::B_FLAT_MAJOR:
				result = "Bb Major";
				break;
			case key_t::B_FLAT_MINOR:
				result = "Bb Minor";
				break;
			case key_t::B_MAJOR:
				result = "B Major";
				break;
			case key_t::B_MINOR:
				result = "B Minor";
				break;
			case key_t::C_MAJOR:
				result = "C Major";
				break;
			case key_t::C_MINOR:
				result = "C Minor";
				break;
			case key_t::D_FLAT_MAJOR:
				result = "Db Major";
				break;
			case key_t::D_FLAT_MINOR:
				result = "Db Minor";
				break;
			case key_t::D_MAJOR:
				result = "D Major";
				break;
			case key_t::D_MINOR:
				result = "D Minor";
				break;
			case key_t::E_FLAT_MAJOR:
				result = "Eb Major";
				break;
			case key_t::E_FLAT_MINOR:
				result = "Eb Minor";
				break;
			case key_t::E_MAJOR:
				result = "E Major";
				break;
			case key_t::E_MINOR:
				result = "E Minor";
				break;
			case key_t::F_MAJOR:
				result = "F Major";
				break;
			case key_t::F_MINOR:
				result = "F Minor";
				break;
			case key_t::G_FLAT_MAJOR:
				result = "Gb Major";
				break;
			case key_t::G_FLAT_MINOR:
				result = "Gb Minor";
				break;
			case key_t::G_MAJOR:
				result = "G Major";
				break;
			case key_t::G_MINOR:
				result = "G Minor";
				break;
			case key_t::A_FLAT_MAJOR:
				result = "Ab Major";
				break;
			case key_t::A_FLAT_MINOR:
				result = "Ab Minor";
				break;
			case key_t::SILENCE:
				result = "SIL";
				break;
			case key_t::UNANALYZED:
				result = "NON";
				break;
			default:
				result = "ERR";
				break;
		}

		return result;
	}

private:
	KeyNotationConversions() {};
	~KeyNotationConversions() {};
};

#endif // KEYNOTATIONCONVERSIONS_H_INCLUDED
