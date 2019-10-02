#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 20 13:48:56 2019

@author: quant-bot
"""

import numpy as np
import matplotlib.pyplot as plt

def get_data():
    with open("train-images-idx3-ubyte", "rb") as train_image_f:
        train_image = bytearray(train_image_f.read())[16:]
        train_image = np.array(train_image).reshape((60000,784))
    with open("train-labels-idx1-ubyte", "rb") as train_lab_f:
        train_lab = bytearray(train_lab_f.read())[8:]
        train_lab = np.array(train_lab).reshape((60000,1)) 
    with open("t10k-images-idx3-ubyte", "rb") as test_image_f:
        test_image = bytearray(test_image_f.read())[16:]
        test_image = np.array(test_image).reshape((10000,784))
    with open("t10k-labels-idx1-ubyte", "rb") as test_lab_f:
        test_lab = bytearray(test_lab_f.read())[8:]
        test_lab = np.array(test_lab).reshape((10000,1))
    return train_image, train_lab, test_image, test_lab
        
def problem1():
    data = get_data()
    train_image = data[0]
    train_image[train_image > 0] = 1
    train_lab = data[1]   
    test_image = data[2]
    test_image[test_image > 0] = 1
    test_lab = data[3]
    k = np.ones(10)
    d = np.ones((784, 10))
    for i in range(len(train_image)):
        label = np.asscalar(train_lab[i])
        k[label] += 1
        d[:,label] += train_image[i].T
    theta_y = (k+1)/k.sum()
    theta_x = d/k.T

    def get_posterior(data):
        '''return maximum likelihood based based on posterior probability'''
        log_post = np.log(theta_y) + (np.log(theta_x)* data + np.log(1-theta_x)* (1-data)).sum(0)
        post = np.exp(log_post)
        return np.argmax(post)
    
    true_classf = 0
    for i in range(len(test_image)):
        input_vec = test_image[i].reshape((784,1))
        label = np.asscalar(test_lab[i])
        post = get_posterior(input_vec)
        true_classf += (post == label)
    accuracy = true_classf/10000
    print("Naive Bayes accuracy (with Dirichlet prior): " + str(accuracy))



def problem2():
    data = get_data()
    train_image = data[0]
    train_lab = data[1]
    train_lab5_idx = np.array(np.where(train_lab==5))[0]
    train_lab_5_idx = np.array(np.where(train_lab!=5))[0]
    mask = np.random.randint(0,2,size=len(train_lab5_idx), dtype=bool)
    train_img5_rep = train_image[train_lab5_idx]
    train_img5_rep = train_img5_rep[mask][:1000]
    train_img_5_rep = train_image[train_lab_5_idx]
    mask = np.random.randint(0,2,size=len(train_img_5_rep), dtype=bool)
    train_img_5_rep = train_img_5_rep[mask][:1000]
    labels = np.append(np.ones(1000), np.zeros(1000)).reshape((2000,1))
    data = np.append(train_img5_rep, train_img_5_rep, axis=0)
    data = np.append(data, labels, axis=1)
    np.random.shuffle(data)
    train = data[:1800]
    test = data[1800:]
    class_, counts = np.unique(train[:,784], return_counts = True)
    priors = np.vstack((class_, counts)).T
    priors[:,1] = priors[:,1]/priors[:,1].sum()
    mu0 = np.array((-9))
    mu1 = np.array((-9))
    pdf = lambda x,mu, v: np.log(v) + ((x-mu)**2/v)
    
    for i in range(28*28):
        mu0 = np.append(mu0, np.mean(train[train[:,784]==0][:,i]))
        mu1 = np.append(mu1, np.mean(train[train[:,784]==1][:,i]))
    mu0 = mu0[1:]
    mu1 = mu1[1:]
    v0 = np.var(train[train[:,784]==0])
    v1 = np.var(train[train[:,784]==1])
    
    def naive_gauss(data, priors, mu0, mu1, v0, v1, tau):
        '''returns naive based gaussian classfication'''
        predict = []
        for image in range(len(data)):
            likelihood_0, likelihood_1 = 0,0
            for label in range(2):
                p = np.log(priors[label,1])
                v = v0 if label == 0 else v1
                mean = mu0 if label == 0 else mu1
                p += np.apply_along_axis(pdf, 0, test[image,:784], mean, v).sum()
                p *=-0.5
                p -= (28*14) * np.log(2*np.pi)
                if label == 0:
                    likelihood_0 = p
                else:
                    likelihood_1 = p
                argmax_class = 1 if (likelihood_1 - likelihood_0) >= tau else 0
            predict.append(argmax_class)   
        predict = np.array(predict)
        return predict
    
    def get_tpr_fpr(data, tau, priors=priors, mu0=mu0, mu1=mu1, v0=v0, v1=v1):
        '''return true positive rate and false positive rate for plotting ROC curve'''
        pred = naive_gauss(data, priors, mu0, mu1, v0, v1, tau)
        data = data[:,784]
        tp = data[np.logical_and(data==1, data==pred)].shape[0]
        N_pos = data[np.logical_and(data==1, data==pred)].shape[0] + data[np.logical_and(data==1, data!=pred)].shape[0]
        fp = data[np.logical_and(data==0, data!=pred)].shape[0]
        N_neg = data[np.logical_and(data==0, data==pred)].shape[0] + data[np.logical_and(data==0, data!=pred)].shape[0]
        fpr = fp/N_neg
        tpr = tp/N_pos
        return tpr,fpr
    
    taus = np.linspace(0.1, 50, 100)
    x,y = [1], [1]
    for tau in taus:
        r = get_tpr_fpr(test,tau)
        x.append(r[1])
        y.append(r[0])
    x.append(0)
    y.append(0)    
    x = np.array(x)
    y = np.array(y)
    plt.plot(x,y)
    plt.xlabel("False Positive Rate(FPR)")
    plt.ylabel("True Positive Rate(TPR)")
    plt.title("ROC Curve")
    plt.show()
    


def problem3():
    data = get_data()
    train = data[0]
    train_lb = data[1]
    
    sample_digit = lambda d,x: d[np.where(train_lb==x),:][0,:][:250]
    mask = np.arange(600)
    np.random.shuffle(mask)
    
    test = np.vstack((sample_digit(train,1)[200:], sample_digit(train,2)[200:], sample_digit(train,7)[200:]))
    test_lb = np.vstack((sample_digit(train_lb,1)[200:], sample_digit(train_lb,2)[200:], sample_digit(train_lb,7)[200:]))
    
    train = np.vstack((sample_digit(train,1)[:200], sample_digit(train,2)[:200], sample_digit(train,7))[:200])
    train_lb = np.vstack((sample_digit(train_lb,1)[:200], sample_digit(train_lb,2)[:200], sample_digit(train_lb,7)[:200]))
    train = train[mask,:]
    train_lb = train_lb[mask,]
    train_folds = np.array_split(train, 5)
    lb_folds = np.array_split(train_lb, 5)
    
    dist = lambda x,y: np.array([np.linalg.norm(x-yi) for yi in y])
    
    def knn_classify(train, train_lb, validn, val_lb, k=1):
        '''return classification based on mode amongst K closest neighbours '''
        pred = []
        train_lb = train_lb[:,0]
        val_lb = val_lb[:,0]
        for image in validn:
            d = dist(image, train)
            nn = train_lb[d.argsort()[0:k]]
            _, idx, counts = np.unique(nn, return_index=True, return_counts=True)
            index = idx[np.argmax(counts)]
            mode = nn[index]
            pred.append(mode)
        pred = np.array(pred)
        acc = val_lb[pred==val_lb].shape[0]/val_lb.shape[0]
        return k,acc,pred
        
    def cross_val(folds=train_folds,lb_folds=lb_folds, k=[1,3,5,7,9]):
        '''performs five-fold cross validation using different Ks'''
        results = {}
        
        train_sets = np.vstack((folds[:4])), np.vstack((folds[1:])),\
        np.vstack((np.vstack(folds[2:]),folds[0])), np.vstack((np.vstack(folds[3:]),np.vstack(folds[:1]))),\
        np.vstack((np.vstack(folds[4:]),np.vstack(folds[:3])))
        
        labels = np.vstack((lb_folds[:4])), np.vstack((lb_folds[1:])),\
        np.vstack((np.vstack(lb_folds[2:]),lb_folds[0])), np.vstack((np.vstack(lb_folds[3:]),np.vstack(lb_folds[:1]))),\
        np.vstack((np.vstack(lb_folds[4:]),np.vstack(lb_folds[:3])))
        
        test_sets = folds[4], folds[0], folds[1], folds[2], folds[3]
        test_lb = lb_folds[4], lb_folds[0], lb_folds[1], lb_folds[2], lb_folds[3]
        for i in range(len(k)):
            results[k[i]] = knn_classify(train_sets[i], labels[i], test_sets[i], test_lb[i],k[i])[1]
        best_k = max(results, key=results.get)
        return best_k, results[best_k]
    
    def test_acc(folds=np.vstack(train_folds[:]), labels=np.vstack(lb_folds[:]), test=test, test_lb=test_lb):
        k=cross_val()[0]
        _, acc, pred = knn_classify(folds, labels, test, test_lb, k)
        return acc, pred
        
    
    def confusion_plot():
        '''generates plots for correct and incorrect classifications'''
        pred = test_acc()[1][:,np.newaxis]
        idx = np.where(np.logical_and(test_lb==1,test_lb==pred))[0]
        corr = test[idx[0]].reshape(28,28)
        plt.imshow(corr)
        plt.title("Correctly Classified 1")
        plt.show()
        for i in [2,7]:
            idx = np.where(np.logical_and(test_lb==i,test_lb==pred))[0]
            idx1 = np.where(np.logical_and(test_lb==i, test_lb!=pred))[0]
            corr = test[idx[0]].reshape(28,28)
            incorr = test[idx1[0]].reshape(28,28)
            plt.imshow(corr)
            plt.title("Correctly Classified "+str(i))
            plt.show()
            plt.imshow(incorr)
            plt.title("Incorrectly Classified "+str(i))
            plt.show()
    
    def display():
        '''displays problem 3 outputs'''
        output = cross_val()
        test = test_acc()[0]
        print("Best K =", output[0])
        print("Validation Accuracy= ", output[1])
        print("Test Accuracy =", test)
        confusion_plot()
    
    display() 
    
