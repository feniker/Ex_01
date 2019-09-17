#include "LV.h"
#include <iostream>

LorentzVector::LorentzVector()
{
	x_ = 0;
	y_ = 0;
	z_ = 0;
	t_ = 0;
}
LorentzVector::LorentzVector(double newx, double newy, double newz, double newt)
{
	x_ = newx;
	y_ = newy;
	z_ = newz;
	t_ = newt;
}
void LorentzVector::setVector(double newx, double newy, double newz, double newt)
{
	x_ = newx;
	y_ = newy;
	z_ = newz;
	t_ = newt;
}
void LorentzVector::writeVector() const
{
	cout << x_ << " " << y_ << " " << z_ << " " << t_ << endl;
}
void LorentzVector::scanVector()
{
	cin >> x_ >> y_ >> z_ >> t_;
}
double LorentzVector::norm()
{
	return x_ * x_ + y_ * y_ + z_ * z_ - t_ * t_;
}
double LorentzVector::getx() const
{
	return x_;
}
double LorentzVector::gety() const
{
	return y_;
}
double LorentzVector::getz() const
{
	return z_;
}
double LorentzVector::gett() const
{
	return t_;
}
LorentzVector LorentzVector::DirectConvert(double beta) const
{
	LorentzVector New;
	New.z_ = (z_ - beta * t_) / sqrt(1 - beta * beta);
	New.y_ = y_;
	New.x_ = x_;
	New.t_ = (t_ - beta * x_) / sqrt(1 - beta * beta);
	return New;
}
LorentzVector LorentzVector::IndirectConvert(double beta) const
{
	LorentzVector New;
	New.z_ = (z_ + beta * t_) / sqrt(1 + beta * beta);
	New.y_ = y_;
	New.x_ = x_;
	New.t_ = (t_ + beta * x_) / sqrt(1 + beta * beta);
	return New;
}
LorentzVector LorentzVector::operator+ (const LorentzVector& other) const
{
	LorentzVector buf;
	buf.x_ = other.x_ + x_;
	buf.y_ = other.y_ + y_;
	buf.z_ = other.z_ + z_;
	buf.t_ = other.t_ + t_;
	return buf;
}
LorentzVector LorentzVector::operator- (const LorentzVector& other) const
{
	LorentzVector buf;
	buf.x_ = x_ - other.getx();
	buf.y_ = y_ - other.gety();
	buf.z_ = z_ - other.getz();
	buf.t_ = t_ - other.gett();
	return buf;
}
LorentzVector LorentzVector::operator- () const
{
	LorentzVector buf;
	buf.x_ = -this->x_;
	buf.y_ = -this->y_;
	buf.z_ = -this->z_;
	buf.t_ = -this->t_;
	return buf;
}
LorentzVector LorentzVector::operator* (const LorentzVector& other) const
{
	LorentzVector buf;
	buf.x_ = other.getx() * x_;
	buf.y_ = other.gety() * y_;
	buf.z_ = other.getz() * z_;
	buf.t_ = other.gett() * t_ * (-1);
	return buf;
}
LorentzVector operator* (double num, LorentzVector& other)
{
	LorentzVector buf;
	buf.x_ = num * other.x_;
	buf.y_ = num * other.y_;
	buf.z_ = num * other.z_;
	buf.t_ = num * other.t_;
	return buf;

}
LorentzVector LorentzVector::operator* (double num) const
{
	LorentzVector buf;
	buf.x_ = num * x_;
	buf.y_ = num * y_;
	buf.z_ = num * z_;
	buf.t_ = num * t_;
	return buf;
}
LorentzVector LorentzVector::operator+= (const LorentzVector& lv)
{
	this->x_ += lv.x_;
	this->y_ += lv.y_;
	this->z_ += lv.z_;
	this->t_ += lv.t_;
	return *this;
}
LorentzVector LorentzVector::operator-= (const LorentzVector& lv)
{
	this->x_ -= lv.x_;
	this->y_ -= lv.y_;
	this->z_ -= lv.z_;
	this->t_ -= lv.t_;
	return *this;
}
LorentzVector LorentzVector::operator*= (const LorentzVector& lv)
{
	this->x_ *= lv.x_;
	this->y_ *= lv.y_;
	this->z_ *= lv.z_;
	this->t_ *= -lv.t_;
	return *this;
}
LorentzVector LorentzVector::operator*= (double a)
{
	this->x_ *= a;
	this->y_ *= a;
	this->z_ *= a;
	this->t_ *= a;
	return *this;
}
istream& operator>> (istream& is, LorentzVector& lv)
{
	is >> lv.x_;
	is >> lv.y_;
	is >> lv.z_;
	is >> lv.t_;
	return is;
}
ostream& operator<< (ostream& out, const LorentzVector& lv)
{
	out << lv.x_ << " " << lv.y_ << " " << lv.z_ << " " << lv.t_;
	return out;
}