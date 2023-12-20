#include "deck.h"

int _strcmp_PEC(const char *s1_PEC, const char *s2_PEC);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind_PEC(deck_node_t **deck);
void insertion_sort_deck_value_PEC(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares Stings.
 * @s1_PEC: The first string to be compared.
 * @s2_PEC: The second string to be compared.
 *
 * Return: Positive byte difference if s1_PEC > s2_PEC
 *         0 if s1_PEC == s2_PEC
 *         Negative byte difference if s1_PEC < s2_PEC
 */ 
int _strcmp_PEC(const char *s1_PEC, const char *s2_PEC)
{
	while (*s1_PEC && *s2_PEC && *s1_PEC == *s2_PEC)
	{
		s1_PEC++;
		s2_PEC++;
	}

	if (*s1_PEC != *s2_PEC)
		return (*s1_PEC - *s2_PEC);
	return (0);
}

/**
 * get_value_PEC - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value_PEC(deck_node_t *card)
{
	if (_strcmp_PEC(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp_PEC(card->card->value, "1") == 0)
		return (1);
	if (_strcmp_PEC(card->card->value, "2") == 0)
		return (2);
	if (_strcmp_PEC(card->card->value, "3") == 0)
		return (3);
	if (_strcmp_PEC(card->card->value, "4") == 0)
		return (4);
	if (_strcmp_PEC(card->card->value, "5") == 0)
		return (5);
	if (_strcmp_PEC(card->card->value, "6") == 0)
		return (6);
	if (_strcmp_PEC(card->card->value, "7") == 0)
		return (7);
	if (_strcmp_PEC(card->card->value, "8") == 0)
		return (8);
	if (_strcmp_PEC(card->card->value, "9") == 0)
		return (9);
	if (_strcmp_PEC(card->card->value, "10") == 0)
		return (10);
	if (_strcmp_PEC(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp_PEC(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind_PEC - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind_PEC(deck_node_t **deck)
{
	deck_node_t *iter_PEC, *insert_PEC, *tmp;

	for (iter_PEC = (*deck)->next; iter_PEC != NULL; iter_PEC = tmp)
	{
		tmp = iter_PEC->next;
		insert = iter_PEC->prev;
		while (insert_PEC != NULL && insert_PEC->card->kind > iter_PEC->card->kind)
		{
			insert_PEC->next = iter_PEC->next;
			if (iter_PEC->next != NULL)
				iter_PEC->next->prev = insert_PEC;
			iter_PEC->prev = insert_PEC->prev;
			iter_PEC->next = insert_PEC;
			if (insert_PEC->prev != NULL)
				insert_PEC->prev->next = iter_PEC;
			else
				*deck = iter_PEC;
			insert_PEC->prev = iter_PEC;
			insert_PEC = iter_PEC->prev;
		}
	}
}

/**
 * insertion_sort_deck_value_PEC - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value_PEC(deck_node_t **deck)
{
	deck_node_t *iter_PEC, *insert_PEC, *tmp;

	for (iter_PEC = (*deck)->next; iter_PEC != NULL; iter_PEC = tmp)
	{
		tmp = iter_PEC->next;
		insert_PEC = iter_PEC->prev;
		while (insert_PEC != NULL &&
				insert_PEC->card->kind == iter_PEC->card->kind &&
				get_value(insert_PEC) > get_value(iter_PEC))
		{
			insert_PEC->next = iter_PEC->next;
			if (iter_PEC->next != NULL)
				iter_PEC->next->prev = insert_PEC;
			iter_PEC->prev = insert_PEC->prev;
			iter_PEC->next = insert_PEC;
			if (insert_PEC->prev != NULL)
				insert_PEC->prev->next = iter_PEC;
			else
				*deck = iter_PEC;
			insert_PEC->prev = iter_PEC;
			insert_PEC = iter_PEC->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind_PEC(deck);
	insertion_sort_deck_value_PEC(deck);
}
