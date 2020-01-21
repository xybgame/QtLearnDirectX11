#ifndef DXWINDOW_H
#define DXWINDOW_H

#include <QWidget>

#include "d3d11.h"
#include "d3dcompiler.h"

#define XYB_SafeDel(obj)    \
    obj->Release();         \
    obj=0;                  \

class DxWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DxWindow(QWidget *parent = nullptr);

public:
    QPaintEngine *paintEngine() const{return nullptr;}

    float bgcolor[4]={1,0.5,0.5,1};           //我自定义清空背景颜色的颜色值
     ID3D11Device *m_d3dDevice;             //创建D3D主要接口
     ID3D11DeviceContext *m_d3dDevContext;  //创建D3D绘制上下文
     IDXGISwapChain *m_swapChain;           //交换链
     ID3D11Texture2D *m_depthStencilBuffer; //深度和模板缓冲区的Buffer缓存，可以理解为一张窗口图片
     ID3D11DepthStencilView *m_depthStencilView;    //深度模板缓冲区窗口描述
     ID3D11RenderTargetView *m_renderTargetView;    //绘制窗口描述
     ID3D11RasterizerState *m_rasterizeState;       //状态

     D3D11_VIEWPORT viewport;       //我们所看到的视口
public:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    void InitD3D();
    void ResizeD3D();
    void RenderInit();
    void RenderUpdate();

};

#endif // DXWINDOW_H
