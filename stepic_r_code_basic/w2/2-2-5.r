# Анализ данных -- это далеко не всегда заумные академические модели в вакууме. Иногда на основе простых манипуляций можно сделать разумные выводы и облегчить принятие повседневных решений.

# Дата фрейм attitude -- встроенный массив данных, содержащий рейтинг департаментов одной финансовой компании, составленный сотрудниками. Представьте, что вы хотите устраиваться как раз в эту компанию, и дата фрейм (совершенно случайно!) оказался в вашем распоряжении.

# Вы решили, что самое главное для вас -- это возможность учиться новому (learning). Возьмите 5 топовых департаментов по этому показателю. Из этого набора вам более всего подойдёт тот департамент, который имеет наибольшую сумму баллов по трём показателям: реакция на жалобы работников (complaints), надбавки в зависимости от результатов работы (raises) и возможность продвижения (advance).

# Какой же департамент вам выбрать? Напишите его номер XX (номер строки в дата фрейме).

x <- attitude[order(-attitude$learning),]