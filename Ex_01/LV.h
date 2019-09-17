#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class LorentzVector
{
public://написать унарный минус
	LorentzVector();
	LorentzVector(double newx, double newy, double newz, double newt);
	void setVector(double newx, double newy, double newz, double newt);
	void writeVector() const;
	void scanVector();
	double norm();
	double getx() const;
	double gety() const;
	double getz() const;
	double gett() const;
	LorentzVector DirectConvert(double beta) const;
	LorentzVector IndirectConvert(double beta) const;
	LorentzVector operator+ (const LorentzVector& other) const;
	LorentzVector operator- (const LorentzVector& other) const;
	LorentzVector operator- () const;
	LorentzVector operator* (const LorentzVector& other) const;
	friend LorentzVector operator* (double num, LorentzVector& other);
	LorentzVector operator* (double num) const;
	friend istream& operator>> (istream& is, LorentzVector& lv);
	friend ostream& operator<< (ostream& out, const LorentzVector& lv);
	LorentzVector operator+= (const LorentzVector& lv);
	LorentzVector operator-= (const LorentzVector& lv);
	LorentzVector operator*= (const LorentzVector& lv);
	LorentzVector operator*= (double a);
private:
	double x_, y_, z_, t_;
};
