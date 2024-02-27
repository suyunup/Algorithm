def solution(users, emoticons):
    answer = []
    sale = [10,20,30,40]
    max_money=-1
    max_subs=-1
    
    
    sale_len=4
    m=len(emoticons)
    index = [0] * m
    n=len(users)
    emoticons_sale_index =[]
    
    def DFS(L):
        if L == m:
            emoticons_sale_index.append(index[:])
        else:
            for i in range(sale_len):
                index[L] = i
                DFS(L+1)
    DFS(0)
    
    for x in emoticons_sale_index:
        subs = 0
        total_buy=0
        for j in range(n):
            buy=0
            for i in range(m):
                if sale[x[i]] >= users[j][0]:
                    buy += (100-sale[x[i]])*emoticons[i]//100
                    
            if buy >= users[j][1]:
                subs +=1
            else:
                total_buy += buy
            # print("buy:",buy)
            # print("total_buy:",total_buy)
        if subs > max_subs:
            max_subs=subs
            max_buy = total_buy
        elif subs==max_subs and total_buy > max_buy:
            max_subs=subs
            max_buy = total_buy
    return [max_subs,max_buy]
