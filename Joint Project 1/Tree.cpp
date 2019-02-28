#include "Tree.h"



Tree::Tree()
{
	loadImages();
}


Tree::~Tree()
{
}

void Tree::loadImages()
{
	if (!palmTreeTexture.loadFromFile("palmTree.png"))
	{
		//error
	}
	if (!moundTexture.loadFromFile("mound.png"))
	{
		//error
	}
	if (!saplingTexture.loadFromFile("sapling.png"))
	{
		//error
	}
	if (!matureTreeTexture.loadFromFile("matureTree.png"))
	{
		//error
	}

}

void Tree::setUpTree()
{
	palmTree.setPosition(200, 100);
	mound.setPosition(200, 100);
	treeAlive = true;
	grown = false;
	matureTreeHealth = 100;
	health = 100;
	growing = 0;
	planted = false;
	palmTree.setTexture(palmTreeTexture);
	mound.setTexture(moundTexture);
	sapling.setTexture(saplingTexture);
	matureTree.setTexture(matureTreeTexture);
	matureTree.setOrigin(40, 48);	
}

void Tree::treePlanted()
{
	if (planted == true)
	{
		sapling.setTexture(saplingTexture);
		
		growing++;
		if (growing == 1200)
		{
			growing = 0;
			planted = false;
		}
	}
}

void Tree::treeGrown()
{
	if (matureTreeHealth == 0)
	{
		matureTreeHealth = 100;
		grown = false;
	}
	if (grown == true)
	{
		matureTree.setTexture(matureTreeTexture);	
	}	
}

