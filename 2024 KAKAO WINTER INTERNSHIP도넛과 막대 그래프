from collections import defaultdict 
def solution(edges):
    # edge => [start,end]인 배열
    # 노드들은 input 과 output이 존재
    inputDic = defaultdict(int)
    outputDic = defaultdict(int) #defaultdict(int) : 키가 없으면 0
    
    maxnode = -1
    newnode = -1
    stickGraph = 0
    eightGraph = 0
    oneGraph = 0
    
    for i in edges: # edge = [output,input] 순서
        outputDic[i[0]] += 1
        inputDic[i[1]] += 1
        if maxnode < i[0]:
            maxnode = i[0]
        if maxnode <i[1]:
            maxnode = i[1]
        
    for i in range(maxnode):
        #생성한 정점: output>=2, input=0
        if outputDic[i+1] >=2 and inputDic[i+1] ==0:
            newnode =i+1
        #막대그래프 개수: output=0
        if outputDic[i+1] ==0:
            stickGraph +=1
        #8자그래프 개수: output>=2,input>=2
        if outputDic[i+1] >=2 and inputDic[i+1] >=2:
            eightGraph +=1
        
    #도넛그래프 개수: 생성한 정점 output -막대,8자그래프    
    oneGraph=outputDic[newnode]-stickGraph-eightGraph
    answer=[newnode,oneGraph,stickGraph,eightGraph]
    
    return answer
