def solution(today, terms, privacies):
    answer = []
    today_dic = {"year":int(today.split(".")[0]), "month":int(today.split(".")[1]), "day":int(today.split(".")[2])}
    terms_dic ={}
    
    for i in terms:
        terms_dic[i.split(" ")[0]]= int(i.split(" ")[1])
    num = 1
    for i in privacies:
        check_terms = i.split(" ")[1] #적용 약관
        date = i.split(" ")[0] #수집 날짜
        
        add_year=int(date.split(".")[0])
        add_month =terms_dic[check_terms]+int(date.split(".")[1] )
        add_day=int(date.split(".")[2])
        
        if(add_month>12 and add_month%12 ==0):
            add_year+=add_month//12 -1
            add_month=12
        elif(add_month>12):
            add_year+=add_month//12
            add_month=add_month%12
            
        if(add_year < today_dic["year"] or
          (add_year == today_dic["year"] and add_month < today_dic["month"]) or
          (add_year == today_dic["year"] and add_month == today_dic["month"] and add_day <= today_dic["day"])):
            answer.append(num)
        num+=1
    
    return answer
